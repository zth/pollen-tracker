type t;
type fragmentRef;
type fragmentRefSelector('a) =
  {.. "__$fragment_ref__IndexRoot_AddressEntry_vendorFollowUp": t} as 'a;
external getFragmentRef: fragmentRefSelector('a) => fragmentRef = "%identity";

type fragment = {
  .
  "contact": {
    .
    "address": string,
    "firstName": string,
  },
  "agent": {. "brandingColor": string},
  "id": string,
};
type operationType = ReasonRelay.fragmentNode;

module Unions = {};

let node: operationType = [%bs.raw
  {| {
  "kind": "Fragment",
  "name": "IndexRoot_AddressEntry_vendorFollowUp",
  "type": "VendorFollowUp",
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
      "kind": "LinkedField",
      "alias": null,
      "name": "agent",
      "storageKey": null,
      "args": null,
      "concreteType": "Agent",
      "plural": false,
      "selections": [
        {
          "kind": "ScalarField",
          "alias": null,
          "name": "brandingColor",
          "args": null,
          "storageKey": null
        }
      ]
    },
    {
      "kind": "LinkedField",
      "alias": null,
      "name": "contact",
      "storageKey": null,
      "args": null,
      "concreteType": "Contact",
      "plural": false,
      "selections": [
        {
          "kind": "ScalarField",
          "alias": null,
          "name": "firstName",
          "args": null,
          "storageKey": null
        },
        {
          "kind": "ScalarField",
          "alias": null,
          "name": "address",
          "args": null,
          "storageKey": null
        }
      ]
    }
  ]
} |}
];
