use std::error::Error;
use sqlx::Row;

#[tokio::main]
async fn main() -> Result<(), Box<dyn Error>>{
    let psql_url = "postgres://rix@localhost/rix_test";
    let psql_pool = sqlx::postgres::PgPool::connect(psql_url).await?;

    sqlx::migrate!("./migrations").run(&psql_pool).await?;

    let testq = sqlx::query("SELECT 1 + 1 as sum")
        .fetch_one(&psql_pool)
        .await?;

    let testsum: i32 = testq.get("sum");
    println!("{}", testsum);

    Ok(())
}
