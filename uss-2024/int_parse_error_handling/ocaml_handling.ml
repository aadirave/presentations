(*
Function of type String -> Some Int
Returns Some Int if parsing is successful, otherwise returns None
*)
let safe_parse_int s = 
  try Some (int_of_string s)
  with Failure _ -> None

let _ = print_string "Int of string '10' is ";
        match safe_parse_int "10" with
        | Some n -> print_int n
        | None -> print_endline "failed to parse"
