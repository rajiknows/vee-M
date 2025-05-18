use vm::vm::Machine;

pub fn main() -> () {
    let mut machine = Machine::new();
    machine.step();
}
