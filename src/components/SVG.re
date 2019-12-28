[@react.component]
let make = (~className=?) => {
  let className = Cn.make(["fill-current", className->Cn.unpack]);

  <svg className viewBox="0 0 20 20">
    <path
      d="M5 10.828l1.61-1.685 1.887 1.736L13.683 6 15 7.704l-6.548 6.074z"
    />
  </svg>;
};

let default = make;
