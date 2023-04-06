use std::io;
use std::io::Write;
use std::error::Error;

fn main()->Result<(), Box<dyn Error>> {
    let stdout = io::stdout();
    let mut out = io::BufWriter::new(stdout.lock());
    
    let mut input = String::new();
    io::stdin().read_line(&mut input)?;

    let mut x:i32 = input.trim().split_whitespace().map(|i| i.parse().unwrap()).collect::<Vec<_>>()[0];
    let mut y:i32 = input.trim().split_whitespace().map(|i| i.parse().unwrap()).collect::<Vec<_>>()[1];
    let mut w:i32 = input.trim().split_whitespace().map(|i| i.parse().unwrap()).collect::<Vec<_>>()[2];
    let mut h:i32 = input.trim().split_whitespace().map(|i| i.parse().unwrap()).collect::<Vec<_>>()[3];
    
    let mut min : u32 = 10000;
    
    if min > x.abs_diff(w) {
        min = x.abs_diff(w);
    }
    if min > x.abs_diff(0) {
        min = x.abs_diff(0);
    }
    if min > y.abs_diff(h) {
        min = y.abs_diff(h);
    }
    if min > y.abs_diff(0) {
        min = y.abs_diff(0);
    }
    
    writeln!(out, "{min}")?;
    
    // let mut h:i32 = input.trim().split_whitespace().map(|i| i.parse().unwrap()).collect::<Vec<_>>()[0];
    
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