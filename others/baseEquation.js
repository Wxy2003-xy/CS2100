function f() {
    for (let X = 2; X <= 16; X++) {  
        for (let Y = 2; Y <= 16; Y++) {  
            for (let Z = 2; Z <= 16; Z++) {  
                try {
                    let minuend = parseInt('4442', X);
                    let subtrahend = parseInt('1122210', Y);
                    let difference = parseInt('6331', Z);
                    
                    if (minuend - subtrahend === difference) {
                        return { X, Y, Z };
                    }
                } catch (e) {
                    
                    continue;
                }
            }
        }
    }
}

console.log(f());

