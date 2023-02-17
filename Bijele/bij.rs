use std::str::FromStr;

fn main(){
    let mut inp_line = String::new();
    let b1 = std::io::stdin().read_line(&mut inp_line);
    // 1 1 2 2 2 8
    let corrects = vec![1,1,2,2,2,8];
    let mut idx = 0;
    for num in inp_line.split(" ") {
        print!("{}", corrects[idx] - i32::from_str(num).unwrap());
        idx += 1;
    }
    


}