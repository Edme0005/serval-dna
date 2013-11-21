#ifndef __SERVALD_NETWORK_CODING_H
#define __SERVALD_NETWORK_CODING_H

#define NC_HEADER_LEN 7

#define URGENCY_ASAP 0
#define URGENCY_ACK_SOON 1
#define URGENCY_SOON 2
#define URGENCY_IDLE 3

struct nc;

struct nc *nc_new(uint8_t max_window_size, size_t datagram_size);
int nc_free(struct nc *n);
int nc_tx_has_room(struct nc *n);
int nc_tx_enqueue_datagram(struct nc *n, const uint8_t *d, size_t len);
ssize_t nc_tx_produce_packet(struct nc *n, uint8_t *datagram, size_t buffer_size);
int nc_rx_packet(struct nc *n, const uint8_t *payload, size_t len);
ssize_t nc_rx_next_delivered(struct nc *n, uint8_t *payload, size_t buffer_size);
int nc_tx_packet_urgency(struct nc *n);
void nc_dump(struct nc *n);
void nc_state_html(struct strbuf *b, struct nc *nc);

#endif