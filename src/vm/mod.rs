use crate::memory::*;
use std::{fmt::format, usize};

#[warn(dead_code)]
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
    Push(u8),
    Pop(Register),
    AddStack(Register, Register),
}

impl Op {
    pub fn op_value(&self) -> u8 {
        unsafe { *<*const _>::from(self).cast::<u8>() }
    }
}

pub struct Machine {
    pub registers: [u16; 8],
    pub memory: Box<dyn Addressable>,
}

impl Machine {
    pub fn new() -> Self {
        Self {
            registers: [0; 8],
            memory: Box::new(LinearMemory::new(8 * 1024)),
        }
    }

    /**

     instruction  = [ 0 0 0 0 0 0 0 0 | 0 0 0 0 0 0 0 0]
                      OPERATOR        |  ARG(S)
                                      | 8 bit literal
                                      | REG1 | REG2

    */
    pub fn step(&mut self) -> Result<(), String> {
        let pc = self.registers[Register::PC as usize];
        let instruction = self.memory.read2(pc).unwrap();

        let op = instruction & 0xff;

        match op {
            x if x == Op::Nop.op_value() => Ok(()),
            _ => Err(format!("unknown operation 0x{:X}", op)),
        }?;
        self.registers[Register::PC as usize] = pc + 2;
        println!("{} @ {}", instruction, pc);
        Ok(())
    }
}
