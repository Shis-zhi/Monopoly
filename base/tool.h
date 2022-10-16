#ifndef TOOL_H_
#define TOOL_H_

namespace monopoly{
class Tool{
public:
    Tool() = default;
    Tool(const Tool& Tool) = default;
    ~Tool() = default;
    const Tool& operator=(const Tool& tool) = delete;

private:
    //TODO
};
}
#endif