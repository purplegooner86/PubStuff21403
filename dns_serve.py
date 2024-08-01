import socketserver as SocketServer


ips_to_resolve = {"example.com": "127.0.0.1"}
prepared = {}

for d in ips_to_resolve:
    in_dns = b''.join([len(j).to_bytes(1, 'big') + j for j in [i.encode() for i in d.split('.')]])
    prepared[in_dns]['ip_bytes'] = b''.join([int(x).to_bytes(1, 'big') for x in ips_to_resolve[d].split(".")])
    prepared[in_dns]['domain'] = d


class MyDNS(SocketServer.BaseRequestHandler):
    def handle(self):
        dns = self.request[0]
        transid = dns[0:2]
        flags = b'\x81\x80'
        one_answer = b'\x00\x01\x00\x01\x00\x00\x00\x00'
        base_url = dns[12:(12+dns[12:].find(b'\x00'))]
        url = dns[12:]
        query_end = b'\x00\x01\x00\x01'
        query = url[0:url.find(query_end) + len(query_end)]
        
        if query_end not in url:
            query = url[0:url.find(b'\x00\x1c\x00\x01') + len(b'\x00\x1c\x00\x01')]
        
        answers = b'\xc0\x0c\x00\x01\x00\x01\x00\x00\x01\x2b\x00\x04'

        if base_url in prepared:
            answers += prepared[base_url]['ip_bytes']
        else:
            print("default_case")
            answers += b''.join([int(x).to_bytes(1, 'big') for x in "192.168.50.50".split(".")])

        response = transid + flags + one_answer + query + answers
        self.request[1].sendto(response, self.client_address)


IP = "192.168.56.106"

    
SocketServer.UDPServer((IP, 53), MyDNS).serve_forever()
