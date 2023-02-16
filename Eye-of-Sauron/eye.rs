

fn main(){
    let mut line = String::new();
    let _byte_c = std::io::stdin().read_line(&mut line).unwrap();
    //println!("hello {}", line);
    let vec: = line.split("()").collect();
    println!("{}",vec);
    /*if (a.length() == b.length()){
        println!("correct");
    }
    else {
        println!("fix");
    }*/
    



}