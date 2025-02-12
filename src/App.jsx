import { useContext, useState } from "react"
import { Mycontext } from "./context/ContextProvider"
import TaskList from "./components/TaskList"

export default function App() {
  let {getTask} = useContext(Mycontext)
  const [userInput, setuserInput] = useState('')
  const handleOnSubmit = (e) => {
    e.preventDefault()
    if(userInput!='')  getTask(userInput)
  
    setuserInput('')
  }
  return (
    <>
      <div className="h-screen w-screen flex justify-center items-center flex-col bg-mito ">
        <form action="" className="shadow-lg p-5 border flex gap-4 bg-white rounded" onSubmit={handleOnSubmit}>
          <input value={userInput} type="text" className="rounded-md px-3 py-1 bg-transparent outline-none border border-mito" placeholder="Enter your Task..." onChange={(e) => setuserInput(e.target.value)} />
          <button className="bg-mito px-3 py-1 text-white rounded">Add Task</button>
        </form>
        <TaskList/>
      </div>
    </>
  )
}