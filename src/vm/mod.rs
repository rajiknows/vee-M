use crate::memory::*;
use std::usize;

enum Register {
    A,
    B,
    C,
    M,
    /// STACK POINTER
    SP,
    /// PROGRAM COUNTER
    PC,
    /// BASE POINTER
    BP,
    FLAGS,
}

#[repr(u8)]
pub enum Op {
    Nop,
}

pub struct Machine {
    registers: [u16; 8],
    memory: Box<dyn Addressable>,
}

impl Machine {
    pub fn new() -> Self {
        Self {
            registers: [0; 8],
            memory: Box::new(LinearMemory::new(8 * 1024)),
        }
    }

    pub fn step(&mut self) -> Result<(), ()> {
        let pc = self.registers[Register::PC as usize];
        let instruction = self.memory.read2(pc).unwrap();
        // instruction  = [ 0 0 0 0 0 0 0 0 | 0 0 0 0 0 0 0 0]
        //                  OPERATOR        |  ARG(S)
        //                                  | 8 bit literal
        //                                  | REG1 | REG2

        let op = instruction & 0xff;

        match op {
            x if x == Op::Nop as u16 => (),
            _ => (),
        }
        self.registers[Register::PC as usize] = pc + 2;
        println!("{} : {}", instruction, pc);
        Ok(())
    }
}
