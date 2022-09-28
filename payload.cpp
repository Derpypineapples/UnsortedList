#include "payload.h"

payload::payload(int c) { content = c; }

int payload::GetContent() { return content; }
void payload::SetContent(int c) { content = c; }

int content;