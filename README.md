## Minitalk

The Minitalk project is about __communication__ between two programs — a client and a server.
The server receives information from the client through __UNIX signals__, which it must correctly handle, __decode__, and __reassemble__.
The main challenge lies in transmitting data reliably and reconstructing it in the correct order, while avoiding __packet corruption__ or __data loss__.
