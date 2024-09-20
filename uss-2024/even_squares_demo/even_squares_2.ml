let is_even x = (x mod 2 = 0)

let square x = x * x

let sum_squares_of_evens lst = 
  List.fold_left (fun acc x -> if is_even x then acc + square x else acc)
  0 lst

let _ = 
  print_string "Sum of squares of even numbers: ";
  print_int (sum_squares_of_evens [1; 2; 3; 4; 5]);
  print_newline ();
