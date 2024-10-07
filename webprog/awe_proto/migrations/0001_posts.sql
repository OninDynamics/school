CREATE TABLE posts (
    id bigserial,
    title text not null,
    content text not null,
    author text,
    upl_time timestamptz not null
);
