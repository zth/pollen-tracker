[@react.component]
let make = (~emptyText) => {
  <div className="flex h-screen">
    <div className="m-auto flex flex-col items-center">
      <img className="object-cover h-64 w-48" src="/homer.png" />
      <div className="font-semibold text-yellow-800">
        {emptyText |> React.string}
      </div>
    </div>
  </div>;
};

let default = make;
