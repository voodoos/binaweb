/* This is the basic component. */
let component = ReasonReact.statelessComponent("Bouton");

/* Your familiar handleClick from ReactJS. This mandatorily takes the payload,
   then the `self` record, which contains state (none here), `handle`, `reduce`
   and other utilities */
let handleClick = (_event, _self) => Js.log("clicked!");

/* `make` is the function that mandatorily takes `children` (if you want to use
   `JSX). `message` is a named argument, which simulates ReactJS props. Usage:

   `<Page message="hello" />`

   Which desugars to

   `ReasonReact.element(Page.make(~message="hello", [||]))` */
let make = (~on, ~onClick, _children) => {
  ...component,
  render: self =>
    <button className=(string_of_bool(on) ++ " ui button") onClick>
      (ReasonReact.string(""))
    </button>,
};