use vm::vm::Machine;

pub fn main() -> Result<(), String> {
    let mut vm = Machine::new();
    vm.memory.write(0, 0xff);
    vm.step()?;
    vm.step()?;
    vm.step()?;
    vm.step()
}
