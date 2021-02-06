use std::path::PathBuf;

#[derive(Debug, PartialEq)]
pub struct RelativeImport {
    source: PathBuf,
    dest: PathBuf,
}

impl RelativeImport {
    fn from(source: &PathBuf, dest: &PathBuf) -> Self {
        RelativeImport {
            source: source.to_path_buf(),
            dest: dest.to_path_buf(),
        }
    }
}

// fn split_path(source: &str) -> Vec<&str> {
//     let v: Vec<&str> = source.split('/').collect();
//     println!("{:?}", v);
//     v
// }

#[test]
fn it_works() {
    let source: PathBuf = PathBuf::from("./bin/main.js");
    let dest: PathBuf = PathBuf::from("./lib/lib.js");
        
    assert_eq!(RelativeImport::from(&source, &dest), RelativeImport { &source, &dest });
}
