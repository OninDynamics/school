mod db;
mod ssr;

use std::sync::Arc;

#[tokio::main]
async fn main() {

    const db_cfg: &str = "host=localhost user=client dbname=skibidi";
    println!("AWE Prototype Website is starting...");

    let tera = Arc::new(
        tera::Tera::new("tmpl/**/*").expect("Tera failed to initialize"),
    );


}
