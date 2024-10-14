use std::string::String;
use askama_axum::Template;
use sqlx::Row;

#[derive(Template)]
#[template(path="master.html")]
struct Master {
    articles: String,
}

#[derive(Template)]
#[template(path="fp-article.html")]
struct Article {
    title: String,
    author: String,
    ts: String,
    content: String
}

async fn index() -> impl axum::response::IntoResponse {
    let sql_post = sqlx::query(
        "SELECT * FROM posts;")
        .fetch_one(sql_state.db_pool)
        .await.expect("Smegma Balls");

    Article {
        title: sql_post.get("title"),
        author: match sql_post.try_get("author") {
            Ok(t) => t,
            Err(..) => "".to_string(),
        },
        ts: match sql_post.try_get("ts") {
            Ok(t) => t,
            Err(..) => "".to_string(),
        },
        content: sql_post.get("content"),
    }

    /*
    let page = Master {
    };
    */

    // post.render().expect("Askama Render Panic!")
    // page.render().expect("Askama Render Panic: Master")
}
