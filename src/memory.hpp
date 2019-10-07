//
// Created by mrn on 06.10.19.
//

class Memory {
public:
    u8 mem[65536];

    func operator->() ->  u8* {
        return mem;
    }
private:
};