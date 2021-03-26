use std::{fs, io};
use cmd_lib::{run_fun, run_cmd};

fn main() -> io::Result<()> {
    let list_of_streams = fs::read_to_string(".streams")?;
    let stream_name = choose_stream(&list_of_streams)?;
    execute_stream(&from_name(&stream_name))?;
    Ok(())
}

fn from_name(stream_name: &str) -> String {
    format!("https://twitch.tv/{}", stream_name)
}

fn choose_stream(streams: &str) -> io::Result<String> {
    Ok(run_fun!(echo $streams | wofi --show dmenu)?)
}

fn execute_stream(choice: &str) -> io::Result<()> {
    run_cmd!(mpv $choice)?;
    Ok(())
}
