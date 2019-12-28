// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE

import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as Js_dict from "bs-platform/lib/es6/js_dict.js";
import * as NextSSR from "../utils/NextSSR.bs.js";
import * as RelayEnv from "../utils/RelayEnv.bs.js";
import * as IndexRoot from "../components/IndexRoot.bs.js";
import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";
import * as Caml_option from "bs-platform/lib/es6/caml_option.js";
import * as ReasonRelay from "@dblechoc/reason-relay/src/ReasonRelay.bs.js";
import * as EmptyContent from "../components/EmptyContent.bs.js";
import * as ReactExperimental from "@dblechoc/reason-relay/src/ReactExperimental.bs.js";

function Index(Props) {
  var token = Props.token;
  var queryRecords = Props.queryRecords;
  if (token !== undefined) {
    var environment = RelayEnv.initEnvironment(undefined, queryRecords);
    return React.createElement(ReasonRelay.Context.Provider.make, Curry._4(ReasonRelay.Context.Provider.makeProps, environment, React.createElement(ReactExperimental.Suspense.make, {
                        children: React.createElement(IndexRoot.make, {
                              token: token
                            }),
                        fallback: React.createElement("div", undefined, "Loading...")
                      }), undefined, /* () */0));
  } else {
    return React.createElement(EmptyContent.make, {
                emptyText: "Please provide a referal token!"
              });
  }
}

function fetcher(param) {
  var baseUrl = NextSSR.getBaseUrl(param.req);
  var environment = RelayEnv.initEnvironment(baseUrl, undefined);
  var token = Js_dict.get(param.query, "token");
  return Belt_Option.getWithDefault(Belt_Option.map(token, (function (token) {
                    var variables = {
                      token: token
                    };
                    return Curry._2(IndexRoot.Query.$$fetch, environment, variables).then((function (param) {
                                    var queryRecords = ReasonRelay.RecordSource.toJSON(ReasonRelay.Store.getSource(ReasonRelay.Environment.getStore(environment)));
                                    return Promise.resolve({
                                                token: token,
                                                queryRecords: Caml_option.some(queryRecords)
                                              });
                                  })).catch((function (error) {
                                  console.log("ssr fetch error: ", error);
                                  return Promise.resolve({
                                              token: token,
                                              queryRecords: undefined
                                            });
                                }));
                  })), Promise.resolve({
                  token: undefined,
                  queryRecords: undefined
                }));
}

Index.getInitialProps = fetcher;

var make = Index;

var $$default = Index;

export {
  make ,
  fetcher ,
  $$default ,
  $$default as default,
  
}
/*  Not a pure module */
