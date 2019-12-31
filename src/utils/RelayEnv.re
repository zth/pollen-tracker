%raw
"require('isomorphic-fetch')";

exception Graphql_error(string);

open ReasonRelay.Network;

let createFetchQuery =
    (~baseUrl: option(string), operation, variables, _cacheConfig) => {
  Fetch.(
    fetchWithInit(
      baseUrl->Belt.Option.getWithDefault("") ++ "/api/graphql",
      Fetch.RequestInit.make(
        ~method=Post,
        ~body=
          Js.Dict.fromList([
            ("query", Js.Json.string(operation.text)),
            ("variables", variables),
          ])
          |> Js.Json.object_
          |> Js.Json.stringify
          |> Fetch.BodyInit.make,
        ~headers=
          Fetch.HeadersInit.make({
            "content-type": "application/json",
            "accept": "application/json",
          }),
        (),
      ),
    )
    |> Js.Promise.then_(resp =>
         if (Response.ok(resp)) {
           Response.json(resp);
         } else {
           Js.Promise.reject(
             Graphql_error("Request failed: " ++ Response.statusText(resp)),
           );
         }
       )
  );
};

let initEnvironment =
    (
      ~baseUrl: option(string),
      ~queryRecords: option(ReasonRelay.recordSourceRecords),
    ) => {
  let network =
    ReasonRelay.Network.makePromiseBased(
      ~fetchFunction=createFetchQuery(~baseUrl),
      (),
    );
  let source =
    switch (queryRecords) {
    | Some(queryRecords) =>
      ReasonRelay.RecordSource.make(~records=queryRecords, ())
    | None => ReasonRelay.RecordSource.make()
    };
  let store = ReasonRelay.Store.make(~source, ());

  ReasonRelay.Environment.make(~network, ~store, ());
};
