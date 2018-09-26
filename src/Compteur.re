/* State declaration */
type state = {ons: array(bool)};

let digits = 8;

/* Action declaration */
type action =
  | Click(int);

/* Component template declaration.
   Needs to be **after** state and action declarations! */
let component = ReasonReact.reducerComponent("Compteur");

let boolToInt = bool_array => {
  let bools =
    String.concat(
      "",
      List.map(b => b ? "1" : "0", Array.to_list(bool_array)),
    );
  int_of_string("0b" ++ bools);
};

let make = _children => {
  /* spread the other default fields of component here and override a few */
  ...component,
  initialState: () => {ons: Array.make(digits, false)},
  /* State transitions */
  reducer: (action, state) =>
    switch (action) {
    | Click(i) =>
      let ons = state.ons;
      ons[i] = ! ons[i];
      ReasonReact.Update({...state, ons});
    },
  render: self => {
    let value = boolToInt(self.state.ons);
    let buttons =
      Array.init(digits, i =>
        <Bouton on=self.state.ons[i] onClick=(_e => self.send(Click(i))) />
      );
    <div className="wrapper">
      <div> <Afficheur value /> </div>
      <div> ...buttons </div>
    </div>;
  },
};