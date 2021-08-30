#![allow(dead_code)]

mod ast;
mod ast_processor;
mod context;
mod error;
mod error_list;
mod literal;
mod parser;
mod unit;

fn main() {
    let mut context = context::CompilerContext::new();
    context.enqueue_file("../Docs/ParseTest.cor");
    context.compile();
}
