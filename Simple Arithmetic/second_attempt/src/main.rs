// Attempt number 2... likely DOES work, but Decimal is not in the rust standard library... hmmmm
use rust_decimal::Decimal;
fn main(){
    let mut line = String::new();
    
    let _bytes_read = std::io::stdin().read_line(&mut line);
    line = line.trim().to_string();

    let iter = line.split(" ");
    let mut float_vec: Vec<Decimal> = Vec::new();
    for val in iter {
        float_vec.push(val.parse::<Decimal>().unwrap());
    }

    let soln = float_vec[0] * (float_vec[1] / float_vec[2]);
    println!("{:.6}", soln);

}
