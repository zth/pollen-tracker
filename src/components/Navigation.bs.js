// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE

import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as ReasonRelay from "reason-relay/src/ReasonRelay.bs.js";
import * as Navigation_agent_graphql from "../__generated__/Navigation_agent_graphql.bs.js";

var convertFragment = Navigation_agent_graphql.Internal.convertFragment;

var UseFragment = ReasonRelay.MakeUseFragment({
      fragmentSpec: Navigation_agent_graphql.node,
      convertFragment: convertFragment
    });

function use(fRef) {
  return Curry._1(UseFragment.use, fRef);
}

var AgentFragment = {
  Operation: /* alias */0,
  Types: /* alias */0,
  UseFragment: UseFragment,
  use: use
};

function Navigation(Props) {
  var agentRef = Props.agentRef;
  var agent = Curry._1(UseFragment.use, agentRef);
  var style = {
    backgroundColor: agent.brandingColor
  };
  return React.createElement("nav", {
              className: "flex w-screen"
            }, React.createElement("div", {
                  className: "h-2 w-full fixed",
                  style: style
                }), React.createElement("div", {
                  className: "w-full"
                }, React.createElement("img", {
                      className: "absolute w-24 mx-3 object-cover",
                      style: style,
                      src: agent.logoUrl
                    })));
}

var make = Navigation;

var $$default = Navigation;

export {
  AgentFragment ,
  make ,
  $$default ,
  $$default as default,
  
}
/* UseFragment Not a pure module */
