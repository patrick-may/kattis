use std::io;

fn tc(entries : i32) -> () {
    for _ in 0..entries {
        let vals: Vec<&str>;
    } 
}
fn main() {
    let mut inp_line = String::new();
    io::stdin().read_line(&mut inp_line).unwrap();
    let mut count: i32 = inp_line
        .trim()
        .parse()
        .unwrap();
    while count != -1 {
        tc();
        io::stdin()
            .read_line(&mut inp_line)
            .unwrap();

        count = inp_line
            .trim()
            .parse()
            .unwrap();
    }
    
}
