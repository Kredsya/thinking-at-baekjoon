use std::io;
use std::io::Write;
use std::error::Error;

fn main()->Result<(), Box<dyn Error>> {
    let stdout = io::stdout();
    let mut out = io::BufWriter::new(stdout.lock());
    
    let mut input = String::new();
    io::stdin().read_line(&mut input)?;
    
    let n : i32 = input.trim().parse()?;
    for _ in 0..n {
        input.clear();
        io::stdin().read_line(&mut input)?;
        let i:Vec<i32> = input.trim().split_whitespace().map(|i| i.parse().unwrap()).collect::<Vec<_>>();
        let H = i[0];
        let N = i[2];
        let mut h = (N - 1) % H + 1;
        let w = (N - 1) / H + 1;
        if w > 9 {
            writeln!(out, "{h}{w}")?;
        }
        else {
            writeln!(out, "{h}0{w}")?;
        }
    }
    
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