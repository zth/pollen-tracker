/* @generated */

module Unions = {};

module Types = {
  type contact = {
    firstName: string,
    address: string,
  };
  type agent = {brandingColor: string};
};

open Types;

type fragment = {
  id: string,
  agent,
  contact,
};

module Internal = {
  type fragmentRaw;
  let fragmentConverter: Js.Dict.t(Js.Dict.t(string)) = [%raw {| {} |}];
  let fragmentConverterMap = ();
  let convertFragment = v =>
    v
    ->ReasonRelay._convertObj(
        fragmentConverter,
        fragmentConverterMap,
        Js.undefined,
      );
};

type t;
type fragmentRef;
type fragmentRefSelector('a) =
  {.. "__$fragment_ref__IndexRoot_AddressEntry_vendorFollowUp": t} as 'a;
external getFragmentRef: fragmentRefSelector('a) => fragmentRef = "%identity";

module Utils = {};

type operationType = ReasonRelay.fragmentNode;

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
