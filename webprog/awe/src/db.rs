use tokio_postgres::{NoTls, Client, Error};
use std::result::Result;

async fn connect(cfg: &str) -> Result<Client, Error> {
    let (client, conn) = { tokio_postgres::connect(
            cfg
            , NoTls)
            .await? };

    tokio::spawn(async move {
        if let Err(e) = conn.await {
            eprintln!("PSQL Error: {}", e);
        }
    });

    Ok(client)
}
