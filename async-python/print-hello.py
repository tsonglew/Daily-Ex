import asyncio

loop = asyncio.get_event_loop()

async def print_hello():
    print("hello")
    await asyncio.sleep(3)
    print("world!")

if __name__ == "__main__":
    loop.run_until_complete(print_hello())