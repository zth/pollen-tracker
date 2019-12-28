type t;
type fragmentRef;
type fragmentRefSelector('a) =
  {.. "__$fragment_ref__Navigation_agent": t} as 'a;
external getFragmentRef: fragmentRefSelector('a) => fragmentRef = "%identity";

type fragment = {
  .
  "logoUrl": string,
  "brandingColor": string,
  "id": string,
};
type operationType = ReasonRelay.fragmentNode;

module Unions = {};

let node: operationType = [%bs.raw
  {| {
  "kind": "Fragment",
  "name": "Navigation_agent",
  "type": "Agent",
  "metadata": null,
  "argumentDefinitions": [],
  "selections": [
    {
      "kind": "ScalarField",
      "alias": null,
      "name": "id",
      "args": null,
      "storageKey": null
    },
    {
      "kind": "ScalarField",
      "alias": null,
      "name": "brandingColor",
      "args": null,
      "storageKey": null
    },
    {
      "kind": "ScalarField",
      "alias": null,
      "name": "logoUrl",
      "args": null,
      "storageKey": null
    }
  ]
} |}
];
