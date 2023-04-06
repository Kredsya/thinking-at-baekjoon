use std::io;
use std::io::Write;
use std::error::Error;

fn check_prime(i : u32) -> i32 {
    if i == 1 {
        0
    }
    else if i == 2 {
        1
    }
    else if i % 2 == 0 {
        0
    }
    else {
        let mut flag : bool = true;
        for j in (3..i).step_by(2) {
            if i % j == 0 {
                flag = false;
                break;
            }
        }
        if flag {
            1
        }
        else {
            0
        }
    }
}

fn main()->Result<(), Box<dyn Error>> {
    let stdout = io::stdout();
    let mut out = io::BufWriter::new(stdout.lock());
    
    let mut input = String::new();
    io::stdin().read_line(&mut input)?;
    
    let n : usize = input.trim().parse()?;
    let mut ans : i32 = 0;
    
    input.clear();
    io::stdin().read_line(&mut input)?;
    let v:Vec<u32> = input.trim().split_whitespace().map(|i| i.parse().unwrap()).collect::<Vec<_>>();
    let mut flag : bool = false;
    for i in 0..n {
        flag = true;
        ans += check_prime(v[i])
    }
    
    writeln!(out, "{ans}")?;
    
    // let i:Vec<i32> = input.trim().split_whitespace().map(|i| i.parse().unwrap()).collect::<Vec<_>>();
    
    /*
    input.clear();
    io::stdin().read_line(&mut input)?;
    let mut parts = input.trim().split_whitespace();
    let i : i32 = parts.next().unwrap().parse()?;
    let s : String = parts.next().unwrap().to_string();
    */
    
    //v = input.trim().split_whitespace().map(|i| i.parse::<f64>().unwrap()).collect();
    //let n : i32 = input.trim().parse()?;
    //writeln!(out, "{n}")?;
    
    Ok(())
}