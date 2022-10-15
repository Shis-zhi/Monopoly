#ifndef PROP_H_
#define PROP_H_

namespace monopoly{
class Prop{
public:
    Prop() = default;
    Prop(const Prop& prop) = default;
    ~Prop() = default;
    const Prop& operator=(const Prop& prop) = delete;

private:
    //TODO
};
}
#endif