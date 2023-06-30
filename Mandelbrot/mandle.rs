use std::io; 

fn square_complex(real: f64, comp: f64) -> (f64, f64) {
    let r2 = (real * real) - (comp * comp);
    let c2 = real * comp * 2.0;
    return (r2, c2);
}

fn abs_complex(real: f64, comp: f64) -> f64 {
    let soln = (real * real + comp * comp).sqrt();
    return soln;
}

fn testcase(s: &str, testcase: i32) {
    let vals: Vec<&str> = s.trim().split_whitespace().collect();
    if vals.len() != 3 {
        return;
    }
    let real: f64 = vals[0].parse().unwrap();
    let imag: f64 = vals[1].parse().unwrap();
    let iters: i32 = vals[2].parse().unwrap();

//    print!("Case {}: {} {} {}\n", testcase, real, imag, iters);
    let mut inflag: bool = false;
    let (mut zr, mut zi) = (0.0, 0.0);
    for _ in 0..iters {
        (zr, zi) = square_complex(zr, zi);
        zr += real;
        zi += imag;

        if abs_complex(zr, zi) > 2.0 {
            inflag = true;
            break;
        }
    }
    print!("Case {}: {}\n", testcase, if !inflag {"IN"} else {"OUT"});
}
fn main() {
    let mut i: i32 = 1;
    for line in io::stdin().lines() {
        if let Ok(line) = line {
            testcase(&line, i);
        }
        i += 1;
    }
}
