module AddressEntry = {
  module Fragment = [%relay.fragment
    {|
      fragment IndexRoot_AddressEntry_vendorFollowUp on VendorFollowUp {
        id
        agent {
          brandingColor
        }
        contact {
          firstName
          address
        }
      }
    |}
  ];

  [@react.component]
  let make = (~vendorFollowUpRef) => {
    let vendorFollowUp = Fragment.use(vendorFollowUpRef);

    let (contactAddress, setContactAddress) =
      React.useState(() => vendorFollowUp.contact.address);

    <div className="m-auto max-w-sm">
      <div className="mx-3">
        <span
          className="text-2xl"
          /* Hi {vendorFollowUp.contact.firstName || "Stranger"} */
        />
        <br />
        <span className="text-gray-700">
          {"Let's get started! Please confirm your current residential address."
           |> React.string}
        </span>
        <input
          className="block w-full rounded-lg border border-gray-400 px-3 py-2 font-semibold text-gray-900 placeholder-gray-600 mt-4 focus:outline-none focus:shadow-outline"
          placeholder="Please enter your address"
          value=contactAddress
          onChange={event => {
            setContactAddress(ReactEvent.Form.target(event)##value)
          }}
        />
      </div>
    </div>;
  };
};

module Query = [%relay.query
  {|
  query IndexRootVendorFollowUpQuery($token: ID!) {
    vendorFollowUp(token: $token) {
      id
      agent {
        ...Navigation_agent
      }
     ...IndexRoot_AddressEntry_vendorFollowUp
   }
  }
|}
];

[@react.component]
let make = (~token) => {
  let queryData = Query.use(~variables={token: token}, ());

  switch (queryData.vendorFollowUp) {
  | Some(vendorFollowUp) =>
    <Layout>
      <div className="h-screen flex flex-col">
        <Navigation agentRef={vendorFollowUp.agent.getFragmentRefs()} />
        <AddressEntry vendorFollowUpRef={vendorFollowUp.getFragmentRefs()} />
      </div>
    </Layout>
  | None => <EmptyContent emptyText="Followup not found !" />
  };
};

let default = make;