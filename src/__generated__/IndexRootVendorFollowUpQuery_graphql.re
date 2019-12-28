type response = {
  .
  "vendorFollowUp":
    Js.Nullable.t({
      .
      "__$fragment_ref__IndexRoot_AddressEntry_vendorFollowUp": IndexRoot_AddressEntry_vendorFollowUp_graphql.t,
      "agent": {
        .
        "__$fragment_ref__Navigation_agent": Navigation_agent_graphql.t,
      },
      "id": string,
    }),
};
type refetchVariables = {. "token": option(string)};
let makeRefetchVariables = (~token=?, ()): refetchVariables => {
  "token": token,
};
type variables = {. "token": string};
type operationType = ReasonRelay.queryNode;

module Unions = {};

let node: operationType = [%bs.raw
  {| (function(){
var v0 = [
  {
    "kind": "LocalArgument",
    "name": "token",
    "type": "ID!",
    "defaultValue": null
  }
],
v1 = [
  {
    "kind": "Variable",
    "name": "token",
    "variableName": "token"
  }
],
v2 = {
  "kind": "ScalarField",
  "alias": null,
  "name": "id",
  "args": null,
  "storageKey": null
};
return {
  "kind": "Request",
  "fragment": {
    "kind": "Fragment",
    "name": "IndexRootVendorFollowUpQuery",
    "type": "Query",
    "metadata": null,
    "argumentDefinitions": (v0/*: any*/),
    "selections": [
      {
        "kind": "LinkedField",
        "alias": null,
        "name": "vendorFollowUp",
        "storageKey": null,
        "args": (v1/*: any*/),
        "concreteType": "VendorFollowUp",
        "plural": false,
        "selections": [
          (v2/*: any*/),
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
                "kind": "FragmentSpread",
                "name": "Navigation_agent",
                "args": null
              }
            ]
          },
          {
            "kind": "FragmentSpread",
            "name": "IndexRoot_AddressEntry_vendorFollowUp",
            "args": null
          }
        ]
      }
    ]
  },
  "operation": {
    "kind": "Operation",
    "name": "IndexRootVendorFollowUpQuery",
    "argumentDefinitions": (v0/*: any*/),
    "selections": [
      {
        "kind": "LinkedField",
        "alias": null,
        "name": "vendorFollowUp",
        "storageKey": null,
        "args": (v1/*: any*/),
        "concreteType": "VendorFollowUp",
        "plural": false,
        "selections": [
          (v2/*: any*/),
          {
            "kind": "LinkedField",
            "alias": null,
            "name": "agent",
            "storageKey": null,
            "args": null,
            "concreteType": "Agent",
            "plural": false,
            "selections": [
              (v2/*: any*/),
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
              },
              (v2/*: any*/)
            ]
          }
        ]
      }
    ]
  },
  "params": {
    "operationKind": "query",
    "name": "IndexRootVendorFollowUpQuery",
    "id": null,
    "text": "query IndexRootVendorFollowUpQuery(\n  $token: ID!\n) {\n  vendorFollowUp(token: $token) {\n    id\n    agent {\n      ...Navigation_agent\n      id\n    }\n    ...IndexRoot_AddressEntry_vendorFollowUp\n  }\n}\n\nfragment IndexRoot_AddressEntry_vendorFollowUp on VendorFollowUp {\n  id\n  agent {\n    brandingColor\n    id\n  }\n  contact {\n    firstName\n    address\n    id\n  }\n}\n\nfragment Navigation_agent on Agent {\n  id\n  brandingColor\n  logoUrl\n}\n",
    "metadata": {}
  }
};
})() |}
];
