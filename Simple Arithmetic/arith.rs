// first attempt in rust. Passes first set of test cases, where 1 <= a,b,c <= 10
// spent a lot of time trying to get input going...
// but now I look for proper math packages for precision
fn main(){
    let mut line = String::new();
    
    let _bytes_read = std::io::stdin().read_line(&mut line);
    line = line.trim().to_string();

    let iter = line.split(" ");
    let mut float_vec: Vec<f64> = Vec::new();
    for val in iter {
        float_vec.push(val.parse::<f64>().unwrap());
    }

    let soln = float_vec[0] * (float_vec[1] / float_vec[2]);
    println!("{:.6}", soln);

}