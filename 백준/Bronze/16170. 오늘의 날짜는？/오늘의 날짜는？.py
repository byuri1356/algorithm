from datetime import datetime, timezone

def today():
    now = datetime.now(timezone.utc).strftime("%Y-%m-%d")
    
    return now.split("-")

if __name__ == "__main__":
    now = today()
    
    for answer in now:
        print(answer)