mod db;
mod ssr;

#[tokio::main]
async fn main() -> Result<(), i32> {

    println!("AWE Prototype Website is starting...");

    let (sqlclient, sqlconn) = db::connect()
    Ok(())
}
