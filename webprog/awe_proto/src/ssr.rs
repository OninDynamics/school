use std::string::String;
use serde::{Serialize, Deserialize};
use tera::Tera;

#[derive(Serialize)]
struct Article {
    title: String,
    author: String,
    ts: String,
    content: String
}

pub async fn serve(templater: Tera) -> &'static str {
    "test"
}
