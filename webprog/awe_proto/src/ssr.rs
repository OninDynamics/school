use std::string::String;
use std::option::Option;
use sqlx::Row;
use serde::Serialize;
use tera::{Tera, Context};
use axum::response::Html;

#[derive(Serialize)]
struct Article {
    title: String,
    author: Option<String>,
    ts: Option<String>,
    content: String
}

pub async fn serve(tera: Tera, pgconn: &sqlx::PgPool)  -> Html<String> {
    let sql_post = sqlx::query(
        "SELECT * FROM posts;")
        .fetch_one(pgconn)
        .await.unwrap();

    let post = Article{
        title: sql_post.get("title"),
        author: match sql_post.try_get("author") {
            Ok(T) => T,
            Err(E) => None,
        },
        ts: match sql_post.try_get("ts") {
            Ok(T) => T,
            Err(E) => None,
        },
        content: sql_post.get("content"),
    };
    
    match tera.render("article.html", &Context::from_serialize(&post)) {
        Ok(T) => Html(T),
        Err(E) => Html("Tera Serialization Error {E}".to_string()),
    }
}
