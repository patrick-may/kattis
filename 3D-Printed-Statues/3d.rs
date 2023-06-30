use std::io;

fn main() {
    let mut buffer = String::new();
    io::stdin()
        .read_line(&mut buffer)
        .expect("problem happened");
    
    let mut statues: i32 = buffer
        .trim()
        .parse()
        .unwrap();

    let mut days: i32 = 0;
    let mut printers: i32 = 1;
    while statues > 0 {
        if printers < statues {
            printers += printers;
        }
        else {
            statues -= printers;
        }
        days += 1;
    } 
    print!("{}", days);
}
