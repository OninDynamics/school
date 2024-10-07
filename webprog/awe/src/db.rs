use tokio_postgres::{NoTls, Client, Connection, Error};
use std::result::Result;

async fn connect() -> Result<(Client, Connection), Error> {
    let (client, conn) = { tokio_postgres::connect(
            "host=localhost user=client dbname=skibidi"
            , NoTls)
            .await? };

    tokio::spawn(async move {
        if let Err(e) = conn.await {
            eprintln!("PSQL Error: {}", e);
            Erro
        }
    });

    Ok((client, conn))
}
