
use std::io;

fn main() {
    let mut buffer = String::new();
    io::stdin()
        .read_line(&mut buffer)
    .expect("Couldn't read from stdin");
  
    let mut iter = buffer.split_whitespace();
    let x: i32 = iter.next().unwrap().parse().unwrap();
    let y: i32 = iter.next().unwrap().parse().unwrap();
    let z: i32 = iter.next().unwrap().parse().unwrap();

    if x + y == z {
        print!("correct!");
    }
    else {
        print!("wrong!");
    }
}
