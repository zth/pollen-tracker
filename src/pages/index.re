open NextSSR;

[@react.component]
let make = (~token, ~queryRecords) => {
  switch (token) {
  | Some(token) =>
    let environment = RelayEnv.initEnvironment(~baseUrl=None, ~queryRecords);

    <ReasonRelay.Context.Provider environment>
      <ReactExperimental.Suspense
        fallback={<div> {React.string("Loading...")} </div>}>
        <IndexRoot token />
      </ReactExperimental.Suspense>
    </ReasonRelay.Context.Provider>;
  | None => <EmptyContent emptyText="Please provide a referal token!" />
  };
};

type props = {
  token: option(string),
  queryRecords: option(ReasonRelay.recordSourceRecords),
};

let fetcher: propsFetcher(props) =
  ({query, req, _}) => {
    let baseUrl = getBaseUrl(req);
    let environment = RelayEnv.initEnvironment(~baseUrl, ~queryRecords=None);
    let token = query->Js.Dict.get("token");

    token
    ->Belt.Option.map(token => {
        Js.Promise.(
          IndexRoot.Query.fetch(~environment, ~variables={token: token})
          |> then_(_ => {
               let queryRecords =
                 ReasonRelay.(
                   environment
                   ->Environment.getStore
                   ->Store.getSource
                   ->RecordSource.toJSON
                 );

               resolve({
                 token: Some(token),
                 queryRecords: Some(queryRecords),
               });
             })
          |> catch(error => {
               Js.log2("ssr fetch error: ", error);
               resolve({token: Some(token), queryRecords: None});
             })
        )
      })
    ->Belt.Option.getWithDefault(
        Js.Promise.resolve({token: None, queryRecords: None}),
      );
  };

let default = make;

default->assignPropsFetcher(fetcher);