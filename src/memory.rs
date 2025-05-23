pub trait Addressable {
    fn read(&self, addr: u16) -> Option<u8>;
    fn write(&mut self, addr: u16, value: u8) -> bool;

    fn read2(&self, addr: u16) -> Option<u16> {
        let lo = self.read(addr)? as u16;
        let hi = self.read(addr + 1)? as u16;
        Some(lo | (hi << 8))
    }

    fn write2(&mut self, addr: u16, value: u8) -> bool {
        let lower = value;
        let upper = 0;
        self.write(addr, lower) && self.write(addr + 1, upper)
    }

    fn copy(&mut self, from: u16, to: u16, n: usize) -> bool {
        for i in 0..n {
            let offset = i as u16;
            match self.read(from + offset) {
                Some(v) => {
                    if !self.write(to + offset, v) {
                        return false;
                    }
                }
                None => return false,
            }
        }
        true
    }
}

pub struct LinearMemory {
    bytes: Vec<u8>,
    size: usize,
}

impl LinearMemory {
    pub fn new(n: usize) -> Self {
        Self {
            bytes: vec![0; n],
            size: n,
        }
    }
}

impl Addressable for LinearMemory {
    fn read(&self, addr: u16) -> Option<u8> {
        self.bytes.get(addr as usize).copied()
    }

    fn write(&mut self, addr: u16, value: u8) -> bool {
        if addr < self.size as u16 {
            self.bytes[addr as usize] = value;
            return true;
        }
        false
    }
}
