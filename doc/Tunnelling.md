Tunnelling through the Serval Mesh network
==========================================
[Serval Project][], May 2014

The [Serval Mesh network][], based on the [Mesh Datagram Protocol][MDP], can
provide better packet delivery rates than conventional [UDP][] over a multi-hop
wireless network than, because it uses per-hop retransmission (and, in future,
[linear network coding][]) to reduce the per-hop packet loss rate, and thus
significantly reduce the cumulative multi-hop packet loss rate.  For this
reason, it is attractive to carry [Internet Protocol][IP] traffic over the
Serval Mesh wireless network using a technique called [tunnelling][].

At present, only one tunnelling service is available for the Serval Mesh:

 * tunnelling of [TCP][] byte streams over the [Mesh Stream Protocol][MSP]

Tunnelling TCP over MSP
-----------------------

An MSP tunnel can carry many TCP streams, all initiated from one end, called
the “client”.  The client creates one MSP stream per TCP stream, and each MSP
stream carries two-way data.

The tunnel must be set up at both ends before it can be used:
 * the “server” end must be set up to act as an MSP *listener*:

        $ servald msp listen ZZ

 * the “client” end must be set up to *connect* to the listener once for each
   TCP stream that is to be tunnelled:



[Serval Project]: http://www.servalproject.org/
[Serval mesh network]: http://developer.servalproject.org/dokuwiki/doku.php?id=content:tech:mesh_network
[MDP]: ./Mesh-Datagram-Protocol.md
[MsP]: ./Mesh-Stream-Protocol.md
[UDP]: http://en.wikipedia.org/wiki/User_Datagram_Protocol
[TCP]: http://en.wikipedia.org/wiki/Transmission_Control_Protocol
[IP]: http://en.wikipedia.org/wiki/Internet_Protocol
[linear network coding]: http://en.wikipedia.org/wiki/Linear_network_coding
[tunnelling]: http://en.wikipedia.org/wiki/Tunneling_protocol
