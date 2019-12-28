include Next;

[@bs.get]
external _getInitialProps:
  React.component('props) =>
  Js.Nullable.t(propsFetcherParams => Js.Promise.t('a)) =
  "getInitialProps";

let getInitialProps = component =>
  _getInitialProps(component) |> Js.Nullable.toOption;

let getBaseUrl = req => {
  req->Belt.Option.map(req => {
    let headers = req.headers;

    let protocol =
      headers
      ->Js.Dict.get("x-forwarded-proto")
      ->Belt.Option.getWithDefault("http");

    let host =
      headers
      ->Js.Dict.get("x-forwarded-host")
      ->Belt.Option.getWithDefault(headers->Js.Dict.unsafeGet("host"));

    protocol ++ "://" ++ host;
  });
};
