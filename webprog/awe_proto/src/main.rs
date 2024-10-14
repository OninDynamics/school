mod ssr;
use std::error::Error;
use sqlx::{Pool, Postgres};
use axum::{Router, routing::get};

#[derive(Clone)]
struct State {
    db_pool: Pool<Postgres>,
}

#[tokio::main]
async fn main() -> Result<(), Box<dyn Error>>{
    // PostgreSQL init (via sqlx)
    let psql_url = "postgres://rix@localhost/rix_test";
    let psql_pool = sqlx::postgres::PgPool::connect(psql_url).await?;

    sqlx::migrate!("./migrations").run(&psql_pool).await?;

    let sql_state = State {
        db_pool: psql_pool,
    };

    let app: Router = Router::new()
        .route("/index.html", get(ssr::index)
        .with_state(sql_state)
            );

    let listener = tokio::net::TcpListener::bind("127.0.0.1:8888").await.unwrap();
    axum::serve(listener, app).await.unwrap();

    Ok(())
}
