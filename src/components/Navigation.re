module AgentFragment = [%relay.fragment
  {|
       fragment Navigation_agent on Agent {
         id
         brandingColor
         logoUrl
       }
     |}
];
[@react.component]
let make = (~agentRef) => {
  let agent = AgentFragment.use(agentRef);

  let style = ReactDOMRe.Style.make(~backgroundColor=agent.brandingColor, ());

  <nav className="flex w-screen">
    <div style className="h-2 w-full fixed" />
    <div className="w-full">
      <img
        style
        className="absolute w-24 mx-3 object-cover"
        src={agent.logoUrl}
      />
    </div>
  </nav>;
};

let default = make;